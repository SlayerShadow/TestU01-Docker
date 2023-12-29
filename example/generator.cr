loop{
	bytes = Bytes.new 4
	IO::Memory.new( bytes ).write_bytes rand( UInt32 )
	print String.new( bytes )
}
