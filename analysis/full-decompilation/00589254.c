
void __fastcall FUN_00589254(int *param_1)

{
  int *piVar1;
  int iVar2;
  
  (**(code **)(*param_1 + 0x20))(1);
  param_1[0x60] = -1;
  param_1[0x23] = 0;
  param_1[0x66] = -1;
  param_1[0x6b] = -1;
  param_1[0x68] = 1;
  param_1[0x24] = 0;
  param_1[0x67] = 0;
  param_1[0x25] = 0;
  param_1[0xa2] = 0;
  param_1[0xa3] = 0;
  param_1[0xa4] = 0;
  param_1[10] = 0;
  param_1[0x5a] = 0;
  param_1[0x5b] = 0;
  param_1[9] = 0;
  param_1[0x70] = 0;
  param_1[0x6a] = 0;
  param_1[100] = 3;
  *(undefined1 *)(param_1 + 0x36) = 1;
  *(undefined1 *)((int)param_1 + 0xd9) = 1;
  *(undefined1 *)((int)param_1 + 0xda) = 1;
  *(undefined1 *)((int)param_1 + 0xdb) = 1;
  if ((param_1[2] != 0) && (iVar2 = *(int *)(param_1[2] + 4), iVar2 != 0)) {
    piVar1 = (int *)(iVar2 + 0xac);
    *piVar1 = *piVar1 + 1;
  }
  if (param_1[0x62] != 0) {
    FUN_00589e31();
    param_1[0x62] = 0;
  }
  (**(code **)(*param_1 + 0xfc))();
  (**(code **)(*param_1 + 0x104))(param_1 + 4);
  (**(code **)(*param_1 + 0x104))(param_1 + 0x4f);
  (**(code **)(*param_1 + 0x104))(param_1 + 5);
  FUN_004071be(param_1[0xb],param_1[0xc]);
  param_1[0x28] = 0;
  FUN_0059299a();
  return;
}

