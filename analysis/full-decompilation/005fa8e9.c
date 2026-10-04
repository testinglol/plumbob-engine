
undefined4 __fastcall FUN_005fa8e9(int *param_1)

{
  char cVar1;
  undefined4 uVar2;
  
  cVar1 = (**(code **)(*(int *)param_1[0x19] + 0x1c))();
  if ((cVar1 == '\0') && (param_1[0x1e] != 0)) {
    uVar2 = (**(code **)(*param_1 + 0x70))();
    (**(code **)(*(int *)param_1[0x19] + 0x14))(uVar2);
    return 1;
  }
  return 0;
}

