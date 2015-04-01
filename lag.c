From: The Anomaly <anomaly@voicenet.com>

I admit, this was something of a joke when it was suggested to me about 
10 minutes ago, but then again, I'm sure there are some sadistic imps out 
there who might like this.  If you do actually add this to your mud, I 
request that you use it wisely and hopefully not frequently.

You may have to fiddle with this to get it to work. I wrote it in 5 
minutes, and I'm sure there are some bugs. If you can't get it to work, 
you probably shouldn't be doing anything except looking for a coder. It's 
reasonably straightforward.

Now, without further ado, the wizskill addlag:

=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

void do_addlag(CHAR_DATA *ch, char *argument)
{

	CHAR_DATA *victim;
	char arg1[MAX_STRING_LENGTH];
	int x;

	argument = one_argument(argument, arg1);

	if (arg1[0] == '\0')
	{
		send_to_char("addlag to who?", ch);
		return;
	}

	if ((victim = get_char_world(ch, arg1)) == NULL)
	{
		send_to_char("They're not here.", ch);
		return;
	}

	if ((x = atoi(argument)) <= 0)
	{
		send_to_char("That makes a LOT of sense.", ch);
		return;
	}

	if (x > 100)
	{
		send_to_char("There's a limit to cruel and unusual punishment", ch);
		return;
	}

	send_to_char("Somebody REALLY didn't like you", victim);
	WAIT_STATE(victim, x);
	send_to_char("Adding lag now...", ch);
	return;
}


--
Jeff Schwaber,			
anomaly@voicenet.com	
=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-	
				http://www.voicenet.com/anomaly/sig.html/



/*
 =============================================================================
/   ______ _______ ____   _____   ___ __    _ ______    ____  ____   _____   /
\  |  ____|__   __|  _ \ / ____\ / _ \| \  / |  ____|  / __ \|  _ \ / ____\  \
/  | |__     | |  | |_| | |     | |_| | |\/| | |___   | |  | | |_| | |       /
/  | ___|    | |  | ___/| |   __|  _  | |  | | ____|  | |  | |  __/| |   ___ \
\  | |       | |  | |   | |___| | | | | |  | | |____  | |__| | |\ \| |___| | /
/  |_|       |_|  |_|  o \_____/|_| |_|_|  |_|______|o \____/|_| \_|\_____/  \
\                                                                            /
 ============================================================================

------------------------------------------------------------------------------
ftp://ftp.game.org/pub/mud      FTP.GAME.ORG      http://www.game.org/ftpsite/
------------------------------------------------------------------------------

  This file came from FTP.GAME.ORG, the ultimate source for MUD resources.

------------------------------------------------------------------------------

*/
