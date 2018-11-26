# UE4Shader

* Config/ConsoleVariables.ini は Engine/Config 以下からコピーした I copyed Config/ConsoleVariables.ini from Engine/Config 
~~~
r.ShaderDevelopmentMode=1
r.Shaders.Optimize=0
r.Shaders.KeepDebugInfo=1 
r.DumpShaderDebugInfo=1
r.DumpShaderDebugShortNames=1
~~~
* エディタ上で Ctrl + Shift + . でシェーダの再コンパイルができる Recompile shader Ctrl + Shift + . in editor

* .reg は Visual Studio でシェーダファイルをハイライトするためのもの .reg is for shader file highlight in Visual Studio

<!--
シェーダの開発には DebugEditor ビルドを使うと良い

Config/ConsoleVariables.ini
r.ShaderDevelopmentMode=1       ... エディタを再起動しなくても、コンパイルに失敗した時に再コンパイルを促す
r.Shaders.Optimize=0            ... 最適化をしないのでコンパイル時間が短くなる
r.Shaders.KeepDebugInfo=1       ... デバッグ情報を残し、RenderDocでデバッグしやすくする
r.DumpShaderDebugInfo=1         ... 生成されたHLSLをディスクへ書き出す(空のプロジェクトでも2Gくらいになる)
r.DumpShaderDebugShortNames=1   ... OS下の最大パス長に合うように名前が短くされる
-->