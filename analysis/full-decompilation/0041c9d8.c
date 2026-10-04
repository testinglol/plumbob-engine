
void __fastcall FUN_0041c9d8(int *param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int local_8;
  
  cVar1 = (**(code **)(*param_1 + 0x28))();
  if (cVar1 == '\0') {
    uVar5 = 0xffffffcf;
  }
  else {
    uVar5 = 0;
  }
  FUN_004659fc(uVar5);
  iVar2 = FUN_00401f6f();
  if (iVar2 != 0) {
    return;
  }
  local_8 = 0;
  iVar2 = *(int *)(param_1[6] + 0x10);
  if (0 < iVar2) {
    do {
      uVar5 = FUN_0041bd24(iVar2);
      for (iVar3 = FUN_0041bd6b(uVar5); 0 < iVar3; iVar3 = iVar3 + -1) {
        iVar4 = FUN_0041bc58(uVar5,iVar3);
        if ((*(int *)(iVar4 + 0xc) == -1) &&
           ((**(code **)(*param_1 + 0x7c))(*(undefined4 *)(iVar4 + 8)), local_8 == 0)) {
          local_8 = FUN_00401f6f();
        }
      }
      iVar2 = iVar2 + -1;
    } while (0 < iVar2);
    if (local_8 != 0) goto LAB_0041ca7e;
  }
  local_8 = FUN_004131cb();
LAB_0041ca7e:
  FUN_004659fc(local_8);
  return;
}

