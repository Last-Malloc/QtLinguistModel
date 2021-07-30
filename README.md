[csdn文章地址](https://blog.csdn.net/qq_42283621/article/details/119261638)

[github网址](https://github.com/Last-Malloc/QtLinguistModel)

# 1. 前言

本文利用Qt语言大师工具，实现Qt程序的多国家语言切换，在github上放置的开源代码中同时放置了所使用的 Qt语言大师程序。CSDN上有众多的Qt语言大师使用攻略可以参考，但仍要编写本文的目的，是让自己和他人能够更简单的了解和使用Qt自带的多语言切换。将样例代码和 Qt语言大师 程序 均放在开源项目中，省去读者寻找和下载工具的麻烦。

第2章 给出 使用方法总结

第3章 给出 使用样例重要步骤截图

# 2. 使用方法总结

1. 修改.pro文件，例如要实现中英文间的切换，则添加两个文件分别存储中文和英文，文件名自拟

   ```c++
   TRANSLATIONS = lang_English.ts \
   				   lang_Chinese.ts
   ```

2. Qt Creator -> 工具 -> 外部->Qt语言家->更新翻译，则在当前目录下生成了lang_English.ts 和 lang_Chinese.ts两个文件，ts文件能够自动捕捉到 非自写代码里的 可能用于显示的 文本信息，例如窗口名、控件名、控件当前值等，代码中的文本信息若想被捕捉到，需要用到tr包裹，例如tr("一棵树")，则"一棵树"将会被捕捉到。一种词被tr()一次即可，例如代码中有多个”一棵树"，则只把一个写为tr("一棵树")。

   **这里可能有人会问，我程序中写的显示文本都是中文，需要和英文相互切换，那为什么需要创建lang_English.ts 和 lang_Chinese.ts两个文件而不是lang_English.ts一个文件呢，当我切换成英文是使lang_English.ts生效，切换成中文时使其失效看起来更简单。但是实际上，只要一个文件是中文切换成英文没有问题，英文切换回中文时因为没有目标语言时中文的翻译文件，将不能切换回中文**

3. 用Qt Linguist（Qt 语言大师）软件同时打开两个.ts文件，第一次打开时将弹出选择框选择要翻译的源语言和目标语言，源语言可以不用理会，选择好正确的目标语言即可。例如lang_Chinese.ts选择目标"简体中文"，lang_English.ts 选择目标"English"。

4. 在软件中遍历点击不同的Context和Strings，在Source text的两个translation to中输入对应的翻译。
   例如item:"主窗口"，则在Translation to American English(United States)中输入"main window"，在Translation to 简体中文(中国) 中输入 "主窗口"。

   **若某个显示文本不想参与语言切换，则在这两个空中不输入 或者 在自写代码中不用tr包裹**

5. Qt Creator -> 工具 -> 外部->Qt语言家->发布翻译，则在当前路径下生成了lang_English.qm 和 lang_Chinese.qm两个文件。

   **实际中代码要使用的qm文件，ts文件是中间文件可以删除，但在*调试版本*中不建议删除，因为如果添加了新的控件或新的要参与翻译的文本信息，则修改ts信息，重新Qt Creator -> 工具 -> 外部->Qt语言家->发布翻译即可，如果删除了ts再需要修改则需要重新执行步骤1到4**

6. 使用代码

   ```c++
   //Qt翻译类
   QTranslator ch;
   QTranslator en;
   
   //加载 翻译文件
   en.load("../testLang/lang_English.qm");
   ch.load("../testLang/lang_Chinese.qm");
   
   //当QComboBox的currentIndex切换时，切换软件的语言
   //注意 对象ch和en 最好设置为类变量，如果设置为局部变量，那个除了其作用域后，翻译就失效了
   void on_comboBox_currentIndexChanged(int index)
   {
       if (index == 0)
           qApp->installTranslator(&ch);
       else
           qApp->installTranslator(&en);
       ui->retranslateUi(this);
   }
   ```

   ```c++
   //启动软件时 通过系统的语言环境 设置软件的语言
   int main(int argc, char *argv[])
   {
       QApplication a(argc, argv);
   
       QTranslator ch;
       QTranslator en;
       en.load("../testLang/lang_English.qm");
       ch.load("../testLang/lang_Chinese.qm");
       // 获取系统语言环境
       QLocale locale;
       if (locale.language() == QLocale::Chinese)
           a.installTranslator(&ch);
       else
           a.installTranslator(&en);
       MainWindow w;
       w.show();
       
       return a.exec();
   }
   ```

   ## 如果软件中发现切换语言后，某个类没有成功切换到新的语言(多发生在代码中动态new出的类)，则在该类中重写以下函数。 ##

   ```c++
   //.h
   void changeEvent(QEvent *e);
   
   //.cpp
   void changeEvent(QEvent *e)
   {
       if(e->type() == QEvent::LanguageChange)
       {
           ui->retranslateUi(this);
       }
   }
   ```

   # 3. 使用样例重要步骤截图

       1. 使用 Qt语言大师 打开两个ts文件
          ![image-20210731020325069](https://img-blog.csdnimg.cn/img_convert/91f303b7eabbba558fd940fb074c747a.png)

       2. 依次选择两个文件的目标语言
          ![image-20210731020343764](https://img-blog.csdnimg.cn/img_convert/73ac4b97a9942dbe7e033791db5e0345.png)

   ![image-20210731020359853](https://img-blog.csdnimg.cn/img_convert/ae5e5cbe663eddbaaa4826780549d3a4.png)

       3. 依次点击item，进行翻译
          ![image-20210731020641350](https://img-blog.csdnimg.cn/img_convert/ab5f9b72310f431171c3a392bc6fb899.png)

       4. "中文"和"English"不参与翻译
          ![image-20210731020715263](https://img-blog.csdnimg.cn/img_convert/def2159889b99464a0f454404569be71.png)

![image-20210731020726166](https://img-blog.csdnimg.cn/img_convert/d153265be8c4820f95095e817cc81587.png)

    5. 注意右下角的warning窗口将给出警告 来提醒可能存在的格式错误（当然也可以不予理会，只是提醒而已）

![image-20210731020832088](https://img-blog.csdnimg.cn/img_convert/8de049faad529eb07c0d80b4f80bc830.png)

![image-20210731020845197](https://img-blog.csdnimg.cn/img_convert/5812fffe666ba226297826a79b10569f.png)

    6. 最终效果-中文

![image-20210731021319542](https://img-blog.csdnimg.cn/img_convert/8dac903d7b46cab46313766594cd2d79.png)

![image-20210731021329242](https://img-blog.csdnimg.cn/img_convert/163d41a5c3678b93c5389ab1c73a6df1.png)

![image-20210731021341859](https://img-blog.csdnimg.cn/img_convert/9808089c40faf5233bf0962372ecad4a.png)

![image-20210731021351003](https://img-blog.csdnimg.cn/img_convert/3705eadeabe94820fa1228339b90c341.png)

![image-20210731021406946](https://img-blog.csdnimg.cn/img_convert/a9cbecbdf6d9ebb59c0a22a1995507cf.png)

    6. 最终效果-英文

![image-20210731021758526](https://img-blog.csdnimg.cn/img_convert/b89be402d20e03eb098da711577bc64e.png)

![image-20210731021809914](https://img-blog.csdnimg.cn/img_convert/a5f3a506276907b562f8bb4f507a4562.png)

![image-20210731021817108](https://img-blog.csdnimg.cn/img_convert/d41f3407c409bb8a325577b5436bdf21.png)

![image-20210731021825278](https://img-blog.csdnimg.cn/img_convert/77ba451aa4a4d1670ca974cdd78522a8.png)

![image-20210731021831200](https://img-blog.csdnimg.cn/img_convert/c5d53d13403d12ce8160780fababfd2d.png)