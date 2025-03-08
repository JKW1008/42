#include <iostream>	//	표준 입출력을 위한 헤어
#include <fstream>	// 파일 입출력을 위한 헤더

int	main(int ac, char **av)
{
	//	인자 개수 체크
	if (ac != 4)
	{
		std::cerr << "Error : Invalid number of args" << std::endl;
		std::cerr << "Usage : " << av[0] << "<filename> <string1> <string2>" << std::endl;
		return (1);
	}

	//	string 타입으로 저장
	std::string fileName = av[1];
	std::string s1 = av[2];
	std::string s2 = av[3];
	//	s1 이 빈 문자열인지 체크
	if (s1.empty())
	{
		std::cerr << "Error : stirng1 cannot be empty" << std::endl;
		return (1);
	}
	//	입력 파일 열기
	std::ifstream inFile(fileName);
	if (!inFile.is_open())
	{
		std::cerr << "Error : Cannot open file " << fileName << std::endl;
		return (1);
	}
	// 출력 파일 이름 생성 및 파일 열기
	std::string	outFileName = fileName + ".replace";
	std::ofstream outFile(outFileName);

	if (!outFile.is_open())
	{
		std::cerr << "Error : Cannot create file" << outFileName << std::endl;
		inFile.close();
		return (1);
	}
	//	파일 내용 처리
	std::string	line;
	while (std::getline(inFile, line))	//	한 줄 씩 읽기
	{
		size_t pos = 0;	//	검색 위치
		size_t	start_ps = 0;	// 이전 검색 위치
		std::string	res;	// 결과 문자열

		//	한 줄 마다 모든 s1을 s2로 치환
		while (((pos = line.find(s1, start_ps)) != std::string::npos))
		{
			//	start부터 pos 까지 문자열을 결과에 추가
			res += line.substr(start_ps, pos - start_ps);
			//	s2를 결과에 추가
			res += s2;
			//	다음 검색 시작 위치
			start_ps = pos + s1.length();
		}
		//	남은 문자열 추가
		res += line.substr(start_ps);
		//	결과를 파일에 쓰기
		outFile << res;
		//	파일의 마지막 줄이 아니면 개행 문자 추가
		if (!inFile.eof())
			outFile << std::endl;
	}
	//	닫기
	inFile.close();
	outFile.close();
	return (0);
}