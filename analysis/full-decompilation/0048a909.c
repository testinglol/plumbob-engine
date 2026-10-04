
void __thiscall FUN_0048a909(int param_1,uint param_2,uint param_3,undefined4 param_4,int param_5)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  
  if (*(char *)(param_1 + 0x5d) == '\0') {
    piVar2 = *(int **)(param_1 + 0x2c);
    if (piVar2 == (int *)0x0) {
      return;
    }
  }
  else {
    iVar3 = -1;
    FUN_004860a0();
    if (param_5 == 1) {
      iVar3 = 3;
    }
    else if (param_5 == 2) {
      iVar3 = 0;
    }
    else if (param_5 == 0x10) {
      param_3 = param_3 | 0xf;
      param_2 = param_2 | 0xf;
    }
    FUN_0047bd91(&param_3,&param_2,-*(int *)(DAT_006e54d8 + 0x84) & 3,0x400);
    if ((*(int **)(param_1 + 0x2c) != (int *)0x0) &&
       (cVar1 = (**(code **)(**(int **)(param_1 + 0x2c) + 0x54))(&param_2,param_4,0,0),
       cVar1 != '\0')) {
      (**(code **)(**(int **)(param_1 + 0x2c) + 0x58))(&param_2,param_4,0,0,1);
      if (iVar3 == -1) {
        return;
      }
      FUN_004226ef((int)(((-*(int *)(DAT_006e54d8 + 0x84) & 3U) + iVar3) * 2 + 8) % 8);
      return;
    }
    piVar2 = *(int **)(param_1 + 0x2c);
  }
  (**(code **)(*piVar2 + 0x50))(1);
  return;
}

