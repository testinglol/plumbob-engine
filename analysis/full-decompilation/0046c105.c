
int __thiscall FUN_0046c105(int param_1,undefined4 param_2)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 0x10);
  do {
    if (iVar3 == *(int *)(param_1 + 0x14)) {
LAB_0046c139:
      uVar2 = FUN_0046be80(param_2);
      FUN_0046c3c6(uVar2);
      return *(int *)(param_1 + 0x14) + -0x250;
    }
    cVar1 = FUN_0046be48(param_2);
    if (cVar1 != '\0') {
      if (iVar3 != *(int *)(param_1 + 0x14)) {
        return iVar3;
      }
      goto LAB_0046c139;
    }
    iVar3 = iVar3 + 0x250;
  } while( true );
}

