library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.numeric_std.all;

entity Lab2 is
	port (
		clk    : in std_logic := '0'; -- clk.clk
		rst : in std_logic := '0'  -- rst.reset_n
	);
end entity Lab2;



architecture arch of Lab2 is

    component Lab2_qsys is
        port (
            clk_clk     : in std_logic := 'X'; -- clk
            rst_reset_n : in std_logic := 'X'  -- reset_n

        );
    end component Lab2_qsys;
	 
begin
    u0 : Lab2_qsys
        port map (
            clk_clk     => clk,     -- clk.clk
            rst_reset_n => rst  		-- rst.reset_n
        );
end arch;