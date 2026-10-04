
int __fastcall FUN_004ee426(int param_1)

{
  uint uVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  int iVar5;
  
  iVar5 = 9;
  FUN_00635e55(param_1,0x10,9,&LAB_004ee47f,FUN_0041ffbf);
  piVar3 = (int *)(param_1 + 4);
  uVar4 = 8;
  do {
    uVar1 = uVar4;
    if (uVar4 < 4) {
      uVar1 = 4;
    }
    piVar3[-1] = uVar1;
    if (uVar1 < 0x200) {
      iVar2 = uVar1 << 7;
    }
    else if (uVar1 < 0x800) {
      iVar2 = uVar1 << 5;
    }
    else {
      iVar2 = uVar1 << 4;
    }
    *piVar3 = iVar2;
    piVar3 = piVar3 + 4;
    uVar4 = uVar4 * 2;
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  return param_1;
}

