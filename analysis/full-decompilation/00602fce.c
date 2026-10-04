
undefined1 __fastcall FUN_00602fce(int param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  char cVar4;
  undefined1 uVar5;
  
  uVar5 = 1;
  iVar1 = *(int *)(param_1 + 4);
  iVar2 = *(int *)(iVar1 + 8);
  while (iVar2 != iVar1) {
    piVar3 = *(int **)(iVar2 + 0x14);
    cVar4 = (**(code **)(*piVar3 + 0x10))();
    if (cVar4 == '\0') {
      uVar5 = 0;
    }
    else {
      (**(code **)(*piVar3 + 4))(0);
    }
    FUN_0041674f();
    iVar1 = *(int *)(param_1 + 4);
  }
  return uVar5;
}

