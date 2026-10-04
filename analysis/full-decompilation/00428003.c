
bool FUN_00428003(undefined4 *param_1,undefined4 *param_2)

{
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  FUN_004288b8(*(undefined4 *)(*(int *)(DAT_006e486c + 0x24) + 0x164),&local_8,&local_c);
  FUN_004288b8(*param_1,&local_18,&local_1c);
  FUN_004288b8(*param_2,&local_10,&local_14);
  return (local_1c - local_c) * (local_1c - local_c) + (local_18 - local_8) * (local_18 - local_8) <
         (local_14 - local_c) * (local_14 - local_c) + (local_10 - local_8) * (local_10 - local_8);
}

