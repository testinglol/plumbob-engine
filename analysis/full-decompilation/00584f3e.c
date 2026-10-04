
void __fastcall FUN_00584f3e(int *param_1)

{
  int *piVar1;
  int iVar2;
  
  (**(code **)(*param_1 + 0x20))(1);
  param_1[0x23] = 0;
  *(undefined1 *)(param_1 + 0x36) = 1;
  *(undefined1 *)((int)param_1 + 0xd9) = 1;
  param_1[0x24] = 0;
  *(undefined1 *)((int)param_1 + 0xda) = 1;
  *(undefined1 *)((int)param_1 + 0xdb) = 1;
  param_1[0x25] = 0;
  iVar2 = (**(code **)(*param_1 + 0xac))();
  piVar1 = (int *)(*(int *)(iVar2 + 4) + 0xac);
  *piVar1 = *piVar1 + 1;
  (**(code **)(*param_1 + 0xfc))();
  (**(code **)(*param_1 + 0x104))(param_1 + 4);
  (**(code **)(*param_1 + 0x104))(param_1 + 5);
  FUN_004071be(param_1[0xb],param_1[0xc]);
  param_1[0x28] = 0;
  return;
}

