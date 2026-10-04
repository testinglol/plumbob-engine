
void __fastcall FUN_00549208(int *param_1)

{
  undefined4 *puVar1;
  char cVar2;
  
  cVar2 = (**(code **)(*param_1 + 200))();
  if (cVar2 == '\0') {
    FUN_005e8e14();
    return;
  }
  if ((undefined4 *)param_1[0x42] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[0x42])(1);
  }
  param_1[0x42] = 0;
  if ((int *)param_1[0x6a] != (int *)0x0) {
    (**(code **)(*(int *)param_1[0x6a] + 0x14))(1);
  }
  param_1[0x6a] = 0;
  *(int *)(DAT_006fe8f4 + 0x1fc) = param_1[0x6b];
  puVar1 = (undefined4 *)param_1[0x6c];
  if (puVar1 != (undefined4 *)0x0) {
    (**(code **)*puVar1)(1);
  }
  param_1[0x6c] = 0;
  FUN_005e8e14();
  return;
}

