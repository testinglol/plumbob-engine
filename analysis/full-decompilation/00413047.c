
int __thiscall FUN_00413047(int param_1,int param_2)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  
  if (*(int *)(param_1 + 4) == 0) {
    uVar3 = *(undefined4 *)(param_2 + 4);
    FUN_005b8e25(uVar3);
    cVar1 = FUN_005b9a53(uVar3);
    if (cVar1 == '\0') {
      iVar2 = -0x28;
    }
    else {
      uVar3 = *(undefined4 *)(param_2 + 4);
      FUN_005b8e25(uVar3);
      cVar1 = FUN_005b9796(uVar3);
      iVar2 = (-(uint)(cVar1 != '\0') & 0x27) - 0x27;
    }
  }
  else {
    iVar2 = -0x2f;
  }
  return iVar2;
}

