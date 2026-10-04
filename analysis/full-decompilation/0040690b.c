
void __thiscall FUN_0040690b(int param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  int *piVar6;
  int local_8;
  
  puVar1 = param_2;
  local_8 = 0;
  piVar6 = (int *)(param_1 + 0xc);
  do {
    if ((int *)*piVar6 == (int *)0x0) {
      return;
    }
    iVar2 = (**(code **)(*(int *)*piVar6 + 0x2c))();
    iVar3 = FUN_00401f6f();
    if (iVar3 != 0) {
      uVar4 = FUN_00401f6f();
      FUN_004659fc(uVar4);
      iVar2 = 0;
    }
    for (; (short)iVar2 != 0; iVar2 = iVar2 + -1) {
      param_2 = (undefined4 *)(**(code **)(*(int *)*piVar6 + 0x30))(iVar2);
      for (puVar5 = (undefined4 *)*puVar1; puVar5 != (undefined4 *)puVar1[1]; puVar5 = puVar5 + 1) {
        if ((undefined4 *)*puVar5 == param_2) goto LAB_00406977;
      }
      FUN_0040555d(&param_2);
LAB_00406977:
    }
    local_8 = local_8 + 1;
    piVar6 = piVar6 + 5;
    if (7 < local_8) {
      return;
    }
  } while( true );
}

