
undefined4 __thiscall FUN_005f03df(int param_1,int *param_2,undefined4 *param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 local_f4 [20];
  undefined4 local_a4;
  undefined4 local_90;
  undefined4 local_8c;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  int *local_14;
  int *local_10;
  int *local_c;
  int *local_8;
  
  local_8 = (int *)0x0;
  local_14 = (int *)0x0;
  local_c = (int *)0x0;
  local_10 = (int *)0x0;
  CoCreateInstance((IID *)&DAT_00678370,(LPUNKNOWN)0x0,1,(IID *)&DAT_006782f0,&local_8);
  (**(code **)(*local_8 + 0x30))(local_8,0,1,0);
  (**(code **)(*local_8 + 0x3c))(local_8,DAT_006fec9c,&DAT_00678410,0,&local_14);
  (**(code **)(*local_8 + 0x3c))(local_8,0,&DAT_00678420,1,0);
  iVar1 = (**(code **)(*local_8 + 0x40))(local_8,param_4,0);
  if (iVar1 == 0) {
    (**(code **)*local_14)(local_14,&DAT_006783b0,&local_c);
    _memset(&local_90,0,0x6c);
    local_90 = 0x6c;
    (**(code **)(*local_c + 0x24))(local_c,&local_90,0,0,&local_8c);
    local_8c = 7;
    local_28 = 0x840;
    iVar1 = (**(code **)(*param_2 + 0x18))(param_2,&local_90,&local_10,0);
    _memset(local_f4,0,100);
    local_1c = local_84;
    local_18 = local_88;
    local_f4[0] = 100;
    local_a4 = 0;
    local_24 = 0;
    local_20 = 0;
    (**(code **)(*local_10 + 0x14))(local_10,&local_24,0,&local_24,0x1000400,local_f4);
    if (iVar1 == 0) {
      (**(code **)(*local_c + 0x34))(local_c,local_10,0,0,param_3);
      (**(code **)(*local_8 + 0x1c))(local_8,1);
      (**(code **)(*(int *)*param_3 + 0x18))((int *)*param_3,3,0,0,0);
      Sleep(10);
      *(undefined1 *)(param_1 + 0x74) = 1;
    }
  }
  if (local_8 != (int *)0x0) {
    (**(code **)(*local_8 + 8))(local_8);
  }
  if (local_14 != (int *)0x0) {
    (**(code **)(*local_14 + 8))(local_14);
  }
  if (local_c != (int *)0x0) {
    (**(code **)(*local_c + 8))(local_c);
  }
  if (local_10 != (int *)0x0) {
    (**(code **)(*local_10 + 8))(local_10);
  }
  return 1;
}

