
undefined4 __thiscall FUN_004176d9(int *param_1,int param_2,short param_3,int param_4)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  
  cVar1 = (**(code **)(*param_1 + 0x28))();
  puVar4 = (undefined4 *)0x0;
  if (cVar1 == '\0') {
    uVar5 = 0xffffffcf;
  }
  else {
    uVar5 = 0;
  }
  FUN_004659fc(uVar5);
  iVar2 = FUN_00401f6f();
  if (iVar2 == 0) {
    piVar3 = (int *)param_1[6];
    iVar2 = (int)param_3;
    if (piVar3 != (int *)0x0) {
      do {
        if (param_2 == piVar3[1]) {
          if (param_4 != 0) {
            piVar3[3] = param_4;
          }
          puVar4 = (undefined4 *)piVar3[2];
          for (; (puVar4 != (undefined4 *)0x0 && (1 < iVar2)); iVar2 = iVar2 + -1) {
            puVar4 = (undefined4 *)*puVar4;
          }
        }
        piVar3 = (int *)*piVar3;
      } while (piVar3 != (int *)0x0);
      if (puVar4 != (undefined4 *)0x0) {
        uVar5 = FUN_00417f1a(puVar4,param_4);
        FUN_004659fc(uVar5);
        return puVar4[4];
      }
    }
    cVar1 = (**(code **)(*param_1 + 0x28))();
    if (cVar1 == '\0') {
      uVar5 = 0xffffffcf;
    }
    else {
      uVar5 = 0xffffff9e;
    }
    FUN_004659fc(uVar5);
  }
  return 0;
}

