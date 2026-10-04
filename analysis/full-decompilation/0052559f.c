
undefined4 __fastcall FUN_0052559f(int *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int *local_c;
  int *local_8;
  
  local_c = param_1;
  local_8 = param_1;
  FUN_0052587a(&local_c);
  FUN_0047bd91(&local_8,&local_c,*(undefined4 *)(DAT_006e54d8 + 0x84),0x400);
  FUN_0051eaec();
  uVar3 = 0;
  uVar2 = 1;
  uVar1 = FUN_005259ab(1,0);
  FUN_004a7baa(local_c,local_8,uVar1,uVar2,uVar3);
  (**(code **)(*param_1 + 0xa8))(0,*(undefined1 *)((int)param_1 + 0xe6),0);
  FUN_005254ff(0);
  return 1;
}

