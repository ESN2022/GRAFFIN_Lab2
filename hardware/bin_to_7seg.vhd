library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.numeric_std.all;

entity bin_to_7seg is
	port (
		pio_0 : in std_logic_vector(3 downto 0);
		segment : out std_logic_vector(6 downto 0)
	);
end entity;

architecture arch of bin_to_7seg is
begin
process(pio_0)
	begin
		case pio_0 is
			when "0000" => segment <= "1000000"; -- "0"     
			when "0001" => segment <= "1111001"; -- "1" 
			when "0010" => segment <= "0100100"; -- "2" 
			when "0011" => segment <= "0110000"; -- "3" 
			when "0100" => segment <= "0011001"; -- "4" 
			when "0101" => segment <= "0010010"; -- "5" 
			when "0110" => segment <= "0000010"; -- "6" 
			when "0111" => segment <= "1111000"; -- "7" 
			when "1000" => segment <= "0000000"; -- "8"     
			when "1001" => segment <= "0010000"; -- "9"
			when others => segment <= "1111111"; -- "X"
		end case;
	end process;
end architecture;