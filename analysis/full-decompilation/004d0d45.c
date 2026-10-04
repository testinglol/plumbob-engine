
undefined4 __fastcall FUN_004d0d45(int *param_1)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  
  cVar1 = (**(code **)(*param_1 + 200))();
  if (cVar1 != '\0') {
    iVar2 = FUN_004e609e();
    if (iVar2 != 0) {
      FUN_004e656a();
    }
    FUN_004d1d8a();
    (**(code **)(*param_1 + 0x90))(1,0);
    FUN_005e8e14();
    (**(code **)(*param_1 + 0xcc))(0);
    if (param_1[0x60] != 0) {
      (**(code **)(**(int **)(DAT_006e486c + 0x54) + 0x14))(param_1[0x60]);
      param_1[0x60] = 0;
    }
    thunk_FUN_005a5ae3();
    if ((undefined4 *)param_1[0x55] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)param_1[0x55])(1);
    }
    param_1[0x55] = 0;
    param_1[0x54] = 0;
    param_1[0x61] = 0;
    if ((undefined4 *)param_1[0x46a] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)param_1[0x46a])(1);
    }
    param_1[0x46a] = 0;
    param_1[0x67] = 0;
    param_1[0x459] = 0;
    piVar3 = (int *)(**(code **)(*DAT_006fe8bc + 0x1c))();
    piVar3 = (int *)(**(code **)(*piVar3 + 8))();
    (**(code **)(*piVar3 + 0x1c8))(0);
    FUN_004b7c6b();
    iVar2 = param_1[0x474];
    if (iVar2 != 0) {
      FUN_004d4108();
      FUN_006321f0(iVar2);
    }
    param_1[0x474] = 0;
    if ((undefined4 *)param_1[0x5d] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)param_1[0x5d])(1);
    }
    param_1[0x5d] = 0;
    if (*(int *)(DAT_006fe8f4 + 500) != 0) {
      FUN_005da4c7(*(int *)(DAT_006fe8f4 + 500));
    }
  }
  return 1;
}

