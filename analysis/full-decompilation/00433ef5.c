
void __thiscall FUN_00433ef5(int param_1,int *param_2,undefined4 param_3,int param_4)

{
  short sVar1;
  int *piVar2;
  short sVar3;
  int iVar4;
  int iVar5;
  
  piVar2 = param_2;
  FUN_004341a6(param_4);
  *(int *)(param_1 + 0xf8) = param_2[1];
  *(int *)(param_1 + 0xf4) = *param_2;
  iVar5 = param_2[1];
  *(char *)(param_1 + 0xfd) = (char)(*param_2 >> 4);
  *(char *)(param_1 + 0xfc) = (char)(iVar5 >> 4);
  *(char *)(param_1 + 0xfe) = (char)param_3;
  *(undefined4 *)(param_1 + 0x110) = param_3;
  *(char *)(param_1 + 0xfe) = (char)param_3;
  FUN_00433dbb((int *)(param_1 + 0xf4),param_1 + 0x100);
  sVar3 = FUN_00433c6a(param_2,param_3);
  sVar1 = *(short *)(param_1 + 0x84);
  *(short *)(param_1 + 0x84) = sVar3;
  if ((sVar1 != sVar3) && (*(short *)(param_1 + 0x58) != 0)) {
    FUN_0040766a(0xf3,(int)sVar1);
    FUN_0040766a(0xf3,(int)sVar3);
  }
  param_2 = (int *)0x0;
  iVar5 = (*(int *)(param_1 + 0x134) - *(int *)(param_1 + 0x130)) / 0x24 + -1;
  if (0 < iVar5) {
    param_4 = 0x24;
    do {
      if ((param_4 < 0x24) ||
         ((*(int *)(param_1 + 0x134) - *(int *)(param_1 + 0x130)) / 0x24 + -1 <= (int)param_2)) {
        iVar4 = 0;
      }
      else {
        iVar4 = param_4 + *(int *)(param_1 + 0x130);
      }
      if (iVar4 == 0) {
        iVar4 = 0;
      }
      else {
        iVar4 = FUN_00407498((int)*(short *)(iVar4 + 0x10));
      }
      if (iVar4 != 0) {
        FUN_00433ef5(piVar2,param_3,1);
      }
      param_2 = (int *)((int)param_2 + 1);
      param_4 = param_4 + 0x24;
    } while ((int)param_2 < iVar5);
  }
  return;
}

