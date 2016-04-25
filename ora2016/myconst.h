#define	tybitsfox		"tiany";
#define ORA_PATH		"ex_a011\\NETWORK\\ADMIN\\tnsnames.ora";
#define	INI_FILE		"myset.ini";
#define	MIX_CODE		0x15B729CA;


typedef struct _TAG_DT
{
	char	host[60];
	char	user[20];
	char	pwd[20];
	char	tbname[60];	//±íÃû³Æ
}_TGDT;
union uc
{
	int u;
	unsigned char c[4];
};
typedef struct _TAGBAS
{
	char	uname[20];
	char	pwd[20];
	char	dbname[60];
	char	conn[1024];
	char	fname[1024];
}_tagbas;