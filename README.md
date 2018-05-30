# Uzd-5
## Duomenų failas
![image](https://user-images.githubusercontent.com/12825358/40751041-2b347a6a-6472-11e8-950a-a02e5462331b.png)

## Rezultatų failas
![image](https://user-images.githubusercontent.com/12825358/40751004-08aa7c56-6472-11e8-85e5-ca4bd2157ddc.png)

## Fun things
### Naudojamas map'as:
```c++
std::map<std::string, parametrai> duom;
```
### Kur "parametrai" yra struktura:
```c++
struct parametrai
{
	int kiek;
	std::vector<int>eil;
};
```

### Veiksmų etapai:
#### 1) Nuskaitome string'ą "nuo tarpo iki tarpo"
#### 2) Pašaliname visus simbolius iš to stringo
```c++
void remove(std::string& str, char character)
{
	//Pasalina simbolius
	 size_t pos;
	 while ((pos = str.find(character)) != std::string::npos)
	 {
		 str.erase(pos, 1);	
	 }

}
```
#### 3) transform'inam į upper arba lower formatą (mano atveju į upper)
```c++
std::transform(zodis.begin(), zodis.end(), zodis.begin(), ::toupper);
```
#### 4) Įrasom string'ą i map'ą
#### 5) Nustatome, kiek kartų string'as pasikartoja tekste
```c++
if (duom.find(zodis) != duom.end())
		{
			duom[zodis].kiek++;
			duom[zodis].eil = eilutes_nustatymas(zodis);
		}
		else
		{
			duom[zodis].kiek = 1;
		}
```
#### 6) Nustatome eilutes, kuriuose pasikartoja string'as
```c++
std::vector<int> eilutes_nustatymas(std::string str)
{
	std::ifstream fd("Duomenys.txt");
	std::string zodis;
	std::vector<int>eil;
	int eilute = 1;
	while (std::getline(fd, zodis))
	{
		std::transform(zodis.begin(), zodis.end(), zodis.begin(), ::toupper);
		if (zodis.find(str) != std::string::npos) {
			eil.push_back(eilute);
		}
		eilute++;
	}
	return eil;
}
```
#### 7) Viską atspausdiname į rezultatų failą
