package repl

import (
	//"bufio"
	"fmt"
	"io"
	// "budget/lexer
	// "budget/token
)

const PROMPT = ">> "

func Start(in io.Reader, out io.Writer) {
	// TODO: scanner := bufio.NewScanner(in)
	fmt.Printf("In repl.Start\n")
	fmt.Print(PROMPT)
}
