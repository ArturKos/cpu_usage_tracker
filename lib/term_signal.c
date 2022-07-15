void term(int signum)
{
    signal_number = signum;
    sigterm_received = 1;
}
