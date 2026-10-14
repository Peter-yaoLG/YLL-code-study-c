# 第三方素材与参考来源

以下说明记录本项目使用的素材和参考，不对全部项目内容授予统一许可。

## Kenney 地图模型

作者：Kenney。以下三个官方素材包均标注为 **CC0 1.0**；下载包内的许可文件已核对。

许可全文：[Creative Commons CC0 1.0 Universal](https://creativecommons.org/publicdomain/zero/1.0/)。

| 官方素材包 | 本项目使用的原模型 | 地图 |
| --- | --- | --- |
| [City Kit (Industrial)](https://kenney.nl/assets/city-kit-industrial) | `building-k.obj`、`chimney-large.obj`、`shipping-container-c.obj` | 工业港湾货场 |
| [Castle Kit](https://kenney.nl/assets/castle-kit) | `tower-square.obj`、`wall.obj`、`rocks-large.obj` | 遗迹回廊 |
| [Space Station Kit](https://kenney.nl/assets/space-station-kit) | `computer-wide.obj`、`wall-pillar.obj`、`container-tall.obj` | 星港前哨 |

这九个模型经过坐标归一化、退化三角形清理、三角形法线生成和原始调色纹理的顶点颜色烘焙，随后内嵌到游戏。后三张地图的布局、碰撞与游戏配置由本项目另行制作。

## AK 枪声与短爆头击中声

来源：用户提供的 Counter-Strike 游戏录像。AK 使用 240 毫秒立体声单发片段，保留起音，并让尾音平滑衰减；播放音量在前版基础上降低约 15%。片段以 48kHz PCM16 内嵌并按原音高播放；未包含原始录像、画面、聊天记录或媒体文件元数据。

短爆头击中声是 130 毫秒单声道片段，通过多个命中片段对齐及滤波减少重叠枪声，可能保留少量录音混音残留；每次命中头部播放。

录制不改变原游戏音频的权利归属。本项目未确认这些音效的开放许可，不为其声明 CC0、MIT 或其他开源许可。

## 爆头击杀音效

来源：用户提供的独立 WAV 音频。移除前导等待段，保留音效主体、尾音、立体声和原音高，转换为 48kHz PCM16 内嵌，去除文件元数据。该音效的原作者和开放许可未另行确认，本项目不为其声明开放许可。

## AK 压枪轨迹参考

参考页面：[AimFinder 压枪训练](https://aimfinder.pro/zh/pattern-training)。

本项目参考公开展示的 AK 30 发点位与 600 RPM 射速，并转换为游戏的弹道角度。未确认该参考数据的开放许可，本项目不为其声明 CC0、MIT 或其他开源许可。

## 敌人造型参考

奶蛙、刀盾狗与女巫根据用户提供的参考图片，以程序生成网格重新制作；未内嵌原始图片。女巫参考 Minecraft 风格的方块尖帽、长鼻与紫袍造型，未提取或内嵌该游戏的模型、贴图。参考形象的原作者与许可未另行确认，本项目不为这些形象声明开放许可。

## 豆包造型与登场音乐
豆包 Boss 根据用户确认的豆包应用角色形象，以程序网格重新制作，未嵌入应用头像原图。两段 Boss 登场音乐由用户提供的视频音轨提取，不包含视频画面或原始文件元数据；本项目不为这些参考形象和音频声明开放许可。
