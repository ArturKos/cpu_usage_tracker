void skip_lines(FILE *fp, int numlines)
{
  int cnt = 0;
  int ch;
  while((cnt < numlines) && ((ch = getc(fp)) != EOF))
  {
    if (ch == '\n')
    cnt++;
  }
  return;
}
