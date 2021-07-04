# Noise-generator
A Noise Generation Library written in C++. 

The main types of Noise Generated are:-

## Random Noise
---
A Random NoiseMap with each pixel having a value b/w 0 and 1.
<p align="center">
<img width="600" src="example/1.Noise=R.png" > 
</p>

---
## Perlin Noise
--- 
A Perlin NoiseMap with each pixel's value being dependent on its X and Y component.Each pixel has values b/w 0 and 1. 
<p align="center">
<img width="600" src="example/2.Noise=P.png" >
</p>

---
## Height Map
--- 
A PerlinNoise HeightMap with multiple octaves layered upon each other. Each octave has decreasing amplitude and increasing frequency. Each pixel has values b/w 0 and 1.
<p align="center">
<img width="600" src="example/3.Noise=P+O.png" >
</p>

---
## Color Map
--- 
A PerlinNoise ColorMap with multiple regions, each with its own Color and Height threshold.
<p align="center">
<img width="600" src="example/4.0.0.Noise=P+O+C.png" >
</p>

The transition b/w HeightMap to ColorMap can be seen as:-
<p align="center">
<img width="400" src="example/3.Noise=P+O.png" >
<img width="400" src="example/4.0.0.Noise=P+O+C.png" >
</p>

---
## Falloff Map
--- 
A Falloff Map used to add a border to other maps.
<p align="center">
<img width="600" src="example/4.0.1.Noise=F.png" >
</p>

---
## HeightMap with Falloff
--- 
A HeightMap with Falloff Applied.
<p align="center">
<img width="600" src="example/4.5Noise=P+O+F.png" >
</p>

The transition b/w HeightMap to Falloff version can be seen as:-
<p align="center">
<img width="400" src="example/3.Noise=P+O.png" >
<img width="400" src="example/4.5Noise=P+O+F.png" >
</p>

---
## ColorMap with Falloff
--- 
A ColorMap with Falloff Applied.
<p align="center">
<img width="600" src="example/5.Noise=P+O+C+F.png" >
</p>

The transition b/w ColorMap to Falloff version can be seen as:-
<p align="center">
<img width="400" src="example/4.0.0.Noise=P+O+C.png" >
<img width="400" src="example/5.Noise=P+O+C+F.png" >
</p>
