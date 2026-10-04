
/* Library Function - Single Match
    _init_namebuf
   
   Library: Visual Studio 2003 Release */

void __cdecl init_namebuf(int param_1)

{
  char *pcVar1;
  DWORD DVar2;
  char *pcVar3;
  undefined4 uVar4;
  
  pcVar3 = &DAT_00703b20;
  if (param_1 != 0) {
    pcVar3 = &DAT_00703b30;
  }
  FUN_006358b0(pcVar3,&DAT_006cc070);
  pcVar1 = pcVar3 + 1;
  if ((*pcVar3 != '\\') && (*pcVar3 != '/')) {
    *pcVar1 = '\\';
    pcVar1 = pcVar3 + 2;
  }
  if (param_1 == 0) {
    *pcVar1 = 's';
  }
  else {
    *pcVar1 = 't';
  }
  pcVar1 = pcVar1 + 1;
  uVar4 = 0x20;
  DVar2 = GetCurrentProcessId();
  FUN_0063b31d(DVar2,pcVar1,uVar4);
  FUN_006358c0(pcVar3,&DAT_006c26dc);
  return;
}

