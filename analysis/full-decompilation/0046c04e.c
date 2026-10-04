
void __thiscall FUN_0046c04e(char *param_1,int param_2)

{
  char cVar1;
  short sVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  
  if ((*param_1 != '\0') && (iVar3 = FUN_0046c105(param_2), iVar3 != 0)) {
    cVar1 = FUN_0046bd76(param_2 + 0xa48);
    if (cVar1 == '\0') {
      piVar4 = (int *)FUN_0046c161(iVar3);
      if (piVar4 == (int *)0x0) {
        return;
      }
      if (*piVar4 == 0) {
        *(undefined1 *)(iVar3 + 0x4c) = 1;
      }
      else {
        *(byte *)(iVar3 + 0x4c) = (byte)(*(uint *)(param_2 + 0xacc) >> 5) & 1;
      }
      FUN_0046ba01(param_2);
      if (*(int *)(iVar3 + 0x3c) != 0) {
        FUN_0046c324(iVar3 + 0x14);
      }
      FUN_0046bdc6(param_2,param_2 + 0xa48);
    }
    *(int *)(iVar3 + 0x3c) = *(int *)(iVar3 + 0x3c) + 1;
    iVar5 = FUN_0045c4b5();
    if (iVar5 == 0) {
      sVar2 = FUN_00474941();
      if (sVar2 == 0x2c) {
        *(int *)(iVar3 + 0x40) = *(int *)(iVar3 + 0x40) + 1;
      }
    }
    else {
      *(int *)(iVar3 + 0x44) = *(int *)(iVar3 + 0x44) + 1;
    }
  }
  return;
}

