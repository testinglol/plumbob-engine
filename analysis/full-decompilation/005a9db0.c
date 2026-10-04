
int FUN_005a9db0(char *param_1,uint param_2)

{
  char cVar1;
  uint uVar2;
  
  uVar2 = 0;
  if ((param_1 != (char *)0x0) && ((*(uint *)((&DAT_00703ea0)[param_2 & 0xf] + 0x34) & 0x100) != 0))
  {
    uVar2 = 0xffffffff;
    do {
      if (uVar2 == 0) break;
      uVar2 = uVar2 - 1;
      cVar1 = *param_1;
      param_1 = param_1 + 1;
    } while (cVar1 != '\0');
    uVar2 = ~uVar2;
  }
  return *(int *)((&DAT_00703ea0)[param_2 & 0xf] + 0x30) + uVar2;
}

