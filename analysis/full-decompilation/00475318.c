
void __thiscall FUN_00475318(ushort *param_1,ushort *param_2,int param_3)

{
  uint uVar1;
  ushort *puVar2;
  ushort uVar3;
  
  if (*param_2 == 0xffff) {
    uVar3 = 0xffff;
  }
  else {
    uVar3 = *param_2 & 0x7fff;
  }
  *param_1 = uVar3;
  param_1[1] = param_2[1];
  param_1[2] = param_2[2];
  *(char *)(param_1 + 3) = (char)param_2[3];
  *(undefined1 *)((int)param_1 + 7) = *(undefined1 *)((int)param_2 + 7);
  *(undefined4 *)(param_1 + 4) = *(undefined4 *)(param_2 + 4);
  *(undefined4 *)(param_1 + 6) = *(undefined4 *)(param_2 + 6);
  if (param_3 != 0) {
    uVar1 = (uint)*(byte *)((int)param_1 + 7);
    if (-1 < (int)(uVar1 - 1)) {
      puVar2 = param_1 + 8 + (uVar1 - 1);
      do {
        *puVar2 = *(ushort *)((param_3 - (int)(param_1 + 8)) + (int)puVar2);
        puVar2 = puVar2 + -1;
        uVar1 = uVar1 - 1;
      } while (uVar1 != 0);
    }
  }
  return;
}

