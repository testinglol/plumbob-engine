
int * __thiscall FUN_006321fb(int *param_1,int param_2)

{
  uint uVar1;
  byte bVar2;
  int iVar3;
  undefined1 local_18 [12];
  undefined2 local_c;
  undefined1 uStack_a;
  undefined1 local_9;
  ushort local_8;
  undefined1 uStack_6;
  undefined1 local_5;
  
  local_c = DAT_006c08e4;
  uStack_a = DAT_006c08e6;
  local_9 = 0;
  local_8 = DAT_00689020;
  uStack_6 = DAT_00689022;
  local_5 = 0;
  iVar3 = FUN_006322ac();
  if (iVar3 != 0) {
    if (param_2 != 0) {
      uVar1 = *(uint *)((int)param_1 + *(int *)(*param_1 + 4) + 0x24);
      if ((uVar1 & 0x60) == 0) {
        if ((0 < param_2) && ((uVar1 & 0x400) != 0)) {
          local_8 = CONCAT11(local_8._1_1_,0x2b);
        }
      }
      else {
        if ((uVar1 & 0x40) == 0) {
          local_c = CONCAT11(0x6f,(undefined1)local_c);
        }
        else {
          bVar2 = ~(byte)(uVar1 >> 4);
          local_c = CONCAT11(bVar2,(undefined1)local_c) & 0x20ff | 0x5800;
          local_8 = CONCAT11(bVar2,(undefined1)local_8) & 0x20ff | 0x5800;
        }
        if ((*(byte *)((int)param_1 + *(int *)(*param_1 + 4) + 0x24) & 0x80) != 0) {
          local_8 = CONCAT11(local_8._1_1_,0x30);
        }
      }
    }
    FUN_00635858(local_18,&local_c,param_2);
    FUN_00632520(&local_8,local_18);
    FUN_00632320();
  }
  return param_1;
}

