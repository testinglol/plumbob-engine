
void __thiscall FUN_004ffad0(int *param_1,int param_2)

{
  (**(code **)(*param_1 + 0x60))
            (*(undefined4 *)(param_2 + 0x7c),*(undefined4 *)(param_2 + 0x80),
             *(undefined4 *)(param_2 + 0x84),*(undefined4 *)(param_2 + 0x88));
  param_1[0x43] = *(int *)(param_2 + 0x7c);
  param_1[0x44] = *(int *)(param_2 + 0x80);
  param_1[0x45] = *(int *)(param_2 + 0x84);
  param_1[0x46] = *(int *)(param_2 + 0x88);
  param_1[0x40] = 3;
  return;
}

