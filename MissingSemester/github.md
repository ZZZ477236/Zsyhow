<div align="center"> 
    <h1 style="front-size: 50px;color: #34495e;">github</h1>
</div>

#### 一·将本地仓库推送到远程仓库流程
1. 在github上创建一个仓库
2. cd 到本地仓库并初始化
    ```
    cd /path/to/your/project   # 进入项目目录
    git init                  # 初始化 Git 仓库
    ```
3. 将项目文件添加到仓库
    ```
    git add .                 # 添加所有文件到暂存区
    ```
4. 提交更改
    ```
    git commit -m "Initial commit"  # 提交更改
    ```
5. 将本地仓库与远程仓库关联
    ```
    git remote add origin https://github.com/your-username/my-project.git
    ```
6. 推送本地仓库到远程仓库
    ```
    git push -u origin master  # 将本地仓库推送到远程仓库
    ```
7. 查看远程仓库
    ```
    git remote -v  # 查看远程仓库
    ```
8. 查看本地仓库
    ```
    git status  # 查看本地仓库状态
    ```
9. 查看提交历史
    ```
    git log  # 查看提交历史
    ```
10. 查看分支
    ```
    git branch  # 查看分支
    ```
