# Uzd-5
## Duomenu failas
![image](https://user-images.githubusercontent.com/12825358/40751041-2b347a6a-6472-11e8-950a-a02e5462331b.png)

## Rezultatu failas
![image](https://user-images.githubusercontent.com/12825358/40751004-08aa7c56-6472-11e8-85e5-ca4bd2157ddc.png)

## Fun things
### Naudojamas map'as:
```c++
std::map<std::string, parametrai> duom;
```
### Kur "parametrai yra struktura:
```c++
struct parametrai
{
	int kiek;
	std::vector<int>eil;
};
```

### Veiksmu etapai:
#### 1) Nuskaitom string'a "nu tarpo iki tarpo"
#### 2) Pasalinam visus simbolius is to stringo
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
#### 3) transform'inam i upper arba lower formata (mano atveju i upper)
```c++
std::transform(zodis.begin(), zodis.end(), zodis.begin(), ::toupper);
```
#### 4) Irasom string'a i map'a
#### 5) Nustatom, kiek kartu string'as pasikartoja tekste
#### 5) Nustatom eilutes, kuriuose pasikartoja string'as
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