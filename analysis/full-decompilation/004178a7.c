
void __thiscall FUN_004178a7(int *param_1,int param_2,undefined4 param_3)

{
  int *piVar1;
  char cVar2;
  int iVar3;
  int *piVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined4 uVar7;
  undefined **local_5c [3];
  undefined1 local_50 [64];
  int local_10;
  int *local_c;
  int local_8;
  
  local_c = param_1;
  cVar2 = (**(code **)(*param_1 + 0x28))();
  if (cVar2 == '\0') {
    uVar7 = 0xffffffcf;
  }
  else {
    uVar7 = 0;
  }
  FUN_004659fc(uVar7);
  iVar3 = FUN_00401f6f();
  if (iVar3 != 0) {
    return;
  }
  FUN_0046f824(local_50,0,0x40);
  local_5c[0] = &PTR_FUN_0066651c;
  FUN_0046f8e4(param_3);
  local_8 = 0;
LAB_004178ff:
  piVar1 = (int *)param_1[9];
  piVar4 = (int *)*piVar1;
  if (piVar4 != (int *)piVar1[1]) {
    do {
      iVar3 = FUN_0046f973(param_3);
      param_1 = local_c;
      if (iVar3 == 0) goto LAB_0041792a;
      piVar4 = piVar4 + 0x14;
    } while (piVar4 != (int *)piVar1[1]);
  }
  piVar4 = (int *)0x0;
LAB_0041792a:
  do {
    if (piVar4 == (int *)0x0) {
      return;
    }
    for (puVar5 = (undefined4 *)param_1[6]; puVar5 != (undefined4 *)0x0;
        puVar5 = (undefined4 *)*puVar5) {
      for (puVar6 = (undefined4 *)puVar5[2]; puVar6 != (undefined4 *)0x0;
          puVar6 = (undefined4 *)*puVar6) {
        if (puVar6[3] == *piVar4) {
          local_10 = puVar5[1];
          goto LAB_00417958;
        }
      }
    }
LAB_00417958:
    if (local_10 == param_2) break;
    piVar4 = (int *)FUN_00416e82(piVar4);
  } while( true );
  FUN_0046f8e4(local_5c);
  FUN_0046fa40(local_8);
  local_8 = local_8 + 1;
  goto LAB_004178ff;
}

