#ifndef HARL_HPP
# define HARL_HPP

# include <string>

enum	Level {
	DEBUG,
	INFO,
	WARNING,
	ERROR,
	INVALID
};

class Harl
{
	private:
		Level	getLevel(std::string const &level);
		void	debug(void);
		void	info(void);
		void	warning(void);
		void	error(void);

		typedef void (Harl::*ComplatintFunction)(void);

		struct ComplaintMap
		{
			std::string	level;
			ComplatintFunction	function;
		};

		static	ComplaintMap	complaintMap[4];
		
	public:
		Harl();
		~Harl();
		void	complain(std::string level);
};

#endif