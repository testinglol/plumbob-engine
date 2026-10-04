
void __thiscall
FUN_00492664(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,int param_5)

{
  int iVar1;
  int iVar2;
  
  iVar1 = param_5;
  (**(code **)(*param_1 + 0x1c))(param_2,param_3,param_4,param_5);
  if (((byte)param_1[0xb] & 0xf) == 1) {
    FUN_00492702(&param_2,param_1[0xb] >> 4);
  }
  else if (param_1[0xe] == 0) {
    FUN_00492c37();
  }
  else {
    FUN_00492942();
    iVar2 = FUN_004925a8(param_1 + 0xc);
    param_1[0x10] = (uint)(iVar2 == 0);
    param_1[0xe] = (uint)(byte)(((byte)((ushort)*(undefined2 *)(iVar1 + 0x10) >> 8) & 2 | 4) >> 1);
    *(undefined1 *)((int)param_1 + 0x33) = (char)param_1[0xc];
    *(undefined1 *)(param_1 + 0xd) = *(undefined1 *)((int)param_1 + 0x31);
    *(undefined1 *)((int)param_1 + 0x35) = *(undefined1 *)((int)param_1 + 0x32);
    if ((*(byte *)(param_1 + 0xb) & 0xf) == 0) {
      FUN_004924fd((undefined1 *)((int)param_1 + 0x33),param_1[0x10]);
    }
  }
  return;
}

