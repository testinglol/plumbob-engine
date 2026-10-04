
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __fastcall FUN_0057ca49(undefined4 *param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  
  param_1[0x54] = 0;
  param_1[0x32] = FUN_0057c05d;
  puVar3 = param_1 + 0x5f;
  for (iVar2 = 0x80b; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  }
  uVar1 = (**(code **)(*DAT_006fe8bc + 0x14))();
  *param_1 = uVar1;
  DAT_006f6a78 = param_1;
  FUN_0057bf27();
  FUN_0057bf80(0,0,0);
  FUN_0057bfad(0,0,0xffffffff);
  FUN_00580629(0xf,0x71);
  FUN_00580558(0x18,0x5a);
  FUN_00580629(0x1f,0x11);
  FUN_00580664(0xd,0x32);
  FUN_00580629(0xf,0x71);
  _DAT_006f6908 = &DAT_006f6848;
  _DAT_006f6858 = &DAT_006f6998;
  _DAT_006f6a2c = &DAT_006f6998;
  _DAT_006f690c = 0;
  _DAT_006f685c = 0;
  _DAT_006f69a8 = 0;
  _DAT_006f69ac = 0;
  _DAT_006f6a28 = &DAT_006f69f8;
  _DAT_006f6a08 = 0;
  _DAT_006f6a0c = 0;
  _DAT_006f6914 = 0x20;
  _DAT_006f6918 = 0x400;
  _DAT_006f691c = 0x400;
  _DAT_006f6920 = 0x200;
  _DAT_006f6924 = 0xe10;
  _DAT_006f6928 = 0;
  _DAT_006f692c = 0;
  _DAT_006f6930 = 0;
  _DAT_006f6934 = 0;
  _DAT_006f6938 = 0;
  _DAT_006f693c = 0;
  _DAT_006f6940 = 100;
  _DAT_006f6944 = 10000;
  _DAT_006f6948 = 0;
  _DAT_006f694c = 0;
  _DAT_006f6950 = 0;
  _DAT_006f6954 = 0;
  _DAT_006f6958 = 0;
  _DAT_006f695c = 0;
  _DAT_006f6960 = 0;
  _DAT_006f69e0 = 0x400;
  iVar2 = 0;
  _DAT_006f6964 = 0;
  _DAT_006f6968 = 0;
  _DAT_006f696c = 1;
  _DAT_006f6970 = 0;
  _DAT_006f6974 = 0;
  _DAT_006f6978 = 0;
  _DAT_006f697c = 0;
  _DAT_006f6980 = 0;
  _DAT_006f6984 = 0;
  _DAT_006f6988 = 0;
  _DAT_006f698c = 0;
  _DAT_006f6990 = 0;
  _DAT_006f6864 = 0;
  _DAT_006f6868 = 0;
  _DAT_006f686c = 0x78;
  _DAT_006f6870 = 0;
  _DAT_006f6874 = 0;
  _DAT_006f6878 = 0;
  _DAT_006f687c = 0;
  _DAT_006f6880 = 0x14;
  _DAT_006f6884 = 0;
  _DAT_006f6888 = 0;
  _DAT_006f688c = 0;
  _DAT_006f6890 = 0;
  _DAT_006f6894 = 0;
  _DAT_006f6898 = 0;
  _DAT_006f68ec = 0x80000000;
  _DAT_006f69dc = 0;
  _DAT_006f69e4 = 0;
  _DAT_006f69e8 = 0;
  _DAT_006f69ec = 0;
  if (0 < DAT_006f6a1c) {
    do {
      *(undefined4 *)(DAT_006f6a24 + iVar2 * 4) = *(undefined4 *)(DAT_006f69a4 + iVar2 * 4);
      iVar2 = iVar2 + 1;
    } while (iVar2 < DAT_006f6a1c);
  }
  param_1[0x16] = 0;
  *(undefined1 *)(param_1 + 0x15) = 0;
  param_1[0x16] = param_1[0x16] + 1;
  *(undefined1 *)(param_1 + 0x15) = 1;
  *(undefined1 *)(param_1 + 0x18) = 1;
  return CONCAT31((int3)((uint)iVar2 >> 8),1);
}

