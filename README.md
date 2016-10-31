# 利用GitHub做私有仓库

> 首先在GitHub上新建一个repository，例如命名为maven-repo，用来当做Maven仓库。

> 再将需要上传到仓库的项目用`mvn deploy`命令生成需要上传的文件（例如jar、pom、md5、sha1等各种文件）。在该项目的pom.xml中加入下面配置

```
<distributionManagement>
    <repository>
        <id>file-repository</id>
        <url>file://D:\wngn\maven-repo</url>
    </repository>
</distributionManagement>
```

> 配置中url是文件生成的目录。运行`mvn deploy`命令，会在`D:\wngn\maven-repo`目录下生成一个所需要上传到仓库的文件,文件的命名如下。

```
artifactId-version.jar
artifactId-version.jar.md5         
artifactId-version.jar.sha1        
artifactId-version-sources.jar     
artifactId-version-sources.jar.md5 
artifactId-version-sources.jar.sha1
artifactId-version.pom             
artifactId-version.pom.md5         
artifactId-version.pom.sha1        
```

> 接下来需要把这些文件上传到GitHub上，这一步如果会使用Git命令的话应该会非常熟悉。进入`D:\wngn\maven-repo`目录，运行以下命令将文件提交到GitHub

```
git add --all
git commit -m "#{artifactId}-v#{artifactId} jar commit by #{yyyy-mm-dd}"
git push origin master
```

> GitHub项目对应的文件HTTP下载URL根目录是： (用户名+GitHub仓库名+分支)

```
https://raw.githubusercontent.com/wngn123/maven-repo/master
```

> 现在Maven仓库已经可以立即使用了

```
<repository>
    <id>my-repository</id>
    <url>https://raw.githubusercontent.com/wngn123/maven-repo/master</url>
</repository>
```


