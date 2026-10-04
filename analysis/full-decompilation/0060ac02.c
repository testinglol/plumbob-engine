
int __thiscall
FUN_0060ac02(int param_1,int *param_2,int param_3,int param_4,int param_5,int param_6,int param_7,
            int param_8,int param_9)

{
  int iVar1;
  char cVar2;
  int iVar3;
  int local_34;
  int local_30;
  char local_2c;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  char local_5;
  
  iVar1 = param_4;
  local_5 = '\0';
  local_c = 0;
  local_10 = param_5;
  if (*(char *)(param_1 + 0x20) == '\0') {
    cVar2 = (**(code **)(*param_2 + 0x20))(0x40);
    if (cVar2 == '\0') {
      return 0;
    }
    *(undefined1 *)(param_1 + 0x20) = 1;
    local_5 = '\x01';
  }
joined_r0x0060ac45:
  do {
    if (param_6 == 0) {
LAB_0060acf3:
      if (local_5 != '\0') {
        (**(code **)(*param_2 + 0x24))(0x40);
        *(undefined1 *)(param_1 + 0x20) = 0;
      }
      return local_c;
    }
    param_4 = 0;
    if ((param_8 <= local_10 - param_5) && (local_10 - param_5 < param_9)) {
      param_4 = 1;
    }
    FUN_0060980f(&local_34,local_10,param_6);
    if (local_34 == 0) goto LAB_0060acf3;
    local_10 = local_10 + local_34;
    param_6 = param_6 - local_34;
  } while (local_2c == '\n');
  if (param_7 != 0) {
    local_14 = FUN_0060931d(local_2c);
    local_20 = local_c + param_3;
    local_14 = local_14 + iVar1;
    local_18 = local_20 + local_30;
    local_1c = iVar1;
    cVar2 = FUN_0060ad10();
    if (cVar2 == '\0') goto joined_r0x0060ac45;
  }
  iVar3 = FUN_0060a98a(param_2,local_c + param_3,iVar1,&local_34,param_4);
  local_c = local_c + iVar3;
  goto joined_r0x0060ac45;
}

