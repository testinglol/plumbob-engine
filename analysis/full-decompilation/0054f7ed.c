
void __fastcall FUN_0054f7ed(int param_1)

{
  void *pvVar1;
  int iVar2;
  
  *(undefined4 *)(param_1 + 0xd4) = 0;
  *(undefined4 *)(param_1 + 0xd8) = 0;
  *(undefined4 *)(param_1 + 0xdc) = 0;
  *(undefined4 *)(param_1 + 0xe0) = 0;
  *(undefined4 *)(param_1 + 0xe4) = 0;
  *(undefined4 *)(param_1 + 0xf0) = 0;
  *(undefined4 *)(param_1 + 0xf4) = 0;
  *(undefined4 *)(param_1 + 0xfc) = 0;
  *(undefined4 *)(param_1 + 0x100) = 0;
  pvVar1 = operator_new(0x9c);
  *(int *)(param_1 + 0xec) = (int)pvVar1;
  if (pvVar1 != (void *)0x0) {
    iVar2 = 0;
    do {
      *(undefined4 *)(*(int *)(param_1 + 0xec) + iVar2) = 0;
      iVar2 = iVar2 + 4;
    } while (iVar2 < 0x9c);
  }
  return;
}

