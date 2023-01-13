library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.numeric_std.all;

entity Lab2 is
	port (
		clk    : in std_logic := '0'; -- clk.clk
		rst : in std_logic := '0';  -- rst.reset_n
		segmentout : out std_logic_vector(6 downto 0)
	);
end entity Lab2;



architecture arch of Lab2 is

    component Lab2_qsys is
        port (
            clk_clk     : in std_logic := 'X'; -- clk
            rst_reset_n : in std_logic := 'X';  -- reset_n
				pio_0_export : out std_logic_vector(3 downto 0)  --export
        );
    end component Lab2_qsys;
	 
	 component bin_to_7seg is
		port (
			pio_0 : in std_logic_vector(3 downto 0) ;
			segment : out std_logic_vector(6 downto 0) 
		);
	end component bin_to_7seg;
	
	signal pio_7seg : std_logic_vector(3 downto 0); 
	 
begin
    u0 : Lab2_qsys
        port map (
            clk_clk     => clk,     -- clk.clk
            rst_reset_n => rst,  		-- rst.reset_n
				pio_0_export => pio_7seg 
			);
		  
	u1 : bin_to_7seg
		port map (
			pio_0 => pio_7seg,
			segment => segmentout
		);
end architecture;