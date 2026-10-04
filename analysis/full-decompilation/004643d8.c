
bool FUN_004643d8(short *param_1,short *param_2,undefined4 *param_3)

{
  BOOL BVar1;
  RECT local_44;
  RECT local_34;
  tagRECT local_24;
  int local_14;
  int local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  local_44.top = (LONG)*param_1;
  local_44.bottom = (LONG)param_1[2];
  local_44.left = (LONG)param_1[1];
  local_44.right = (LONG)param_1[3];
  local_34.top = (LONG)*param_2;
  local_34.bottom = (LONG)param_2[2];
  local_34.left = (LONG)param_2[1];
  local_34.right = (LONG)param_2[3];
  local_14 = local_34.left;
  local_10 = local_34.top;
  local_c = local_34.right;
  local_8 = local_34.bottom;
  BVar1 = IntersectRect(&local_24,&local_44,&local_34);
  local_c = CONCAT22((undefined2)local_24.left,(undefined2)local_24.top);
  local_8 = CONCAT22((undefined2)local_24.right,(undefined2)local_24.bottom);
  *param_3 = local_c;
  param_3[1] = local_8;
  return BVar1 != 0;
}

