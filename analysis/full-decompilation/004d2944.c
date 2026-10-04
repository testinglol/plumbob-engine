
void __fastcall FUN_004d2944(int *param_1)

{
  undefined4 uVar1;
  char cVar2;
  undefined4 *puVar3;
  
  for (puVar3 = (undefined4 *)param_1[0x45f]; puVar3 != (undefined4 *)param_1[0x460];
      puVar3 = puVar3 + 1) {
    uVar1 = *puVar3;
    cVar2 = (**(code **)(*param_1 + 0x38))(uVar1);
    if (cVar2 != '\0') {
      FUN_005ddfdc(0);
      (**(code **)(*param_1 + 0x24))(uVar1);
    }
    FUN_005da4c7(uVar1);
  }
  FUN_0042ed71(param_1[0x462],param_1[0x463]);
  for (puVar3 = (undefined4 *)param_1[0x462]; puVar3 != (undefined4 *)param_1[0x463];
      puVar3 = puVar3 + 1) {
    uVar1 = *puVar3;
    cVar2 = (**(code **)(*param_1 + 0x38))(uVar1);
    if (cVar2 != '\0') {
      (**(code **)(*param_1 + 0x24))(uVar1);
    }
    FUN_005da4c7(uVar1);
  }
  FUN_0042ed71(param_1[0x45f],param_1[0x460]);
  return;
}

