
int __thiscall FUN_004174cd(int *param_1,short param_2)

{
  char cVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  
  cVar1 = (**(code **)(*param_1 + 0x28))();
  if (cVar1 == '\0') {
    uVar4 = 0xffffffcf;
  }
  else {
    uVar4 = 0;
  }
  FUN_004659fc(uVar4);
  iVar2 = FUN_00401f6f();
  if (iVar2 == 0) {
    puVar3 = (undefined4 *)param_1[6];
    for (iVar2 = (int)param_2; 1 < iVar2; iVar2 = iVar2 + -1) {
      if (puVar3 == (undefined4 *)0x0) goto LAB_00417515;
      puVar3 = (undefined4 *)*puVar3;
    }
    if (puVar3 == (undefined4 *)0x0) {
LAB_00417515:
      iVar2 = 0;
    }
    else {
      iVar2 = puVar3[1];
    }
    if (iVar2 == 0) {
      FUN_004659fc(0xffffff9c);
    }
  }
  else {
    iVar2 = 0;
  }
  return iVar2;
}

