
void __thiscall FUN_00484ca9(int param_1,uint *param_2)

{
  char cVar1;
  undefined4 uVar2;
  uint local_c;
  uint local_8;
  
  if (*(int *)(param_1 + 0x44) != 0) {
    local_8 = param_2[1] & 0xfffffff0;
    local_c = *param_2 & 0xfffffff0;
    cVar1 = FUN_00484ba0(&local_c);
    if (cVar1 == '\0') {
      FUN_0047bd91(&local_8,&local_c,-*(int *)(DAT_006e54d8 + 0x84) & 3,0x400);
      uVar2 = FUN_00492b26();
      cVar1 = (**(code **)(**(int **)(param_1 + 0x44) + 0x54))(&local_c,uVar2,0,0);
      if (cVar1 != '\0') {
        (**(code **)(**(int **)(param_1 + 0x44) + 0x58))(&local_c,uVar2,0,0,1);
        return;
      }
    }
    (**(code **)(**(int **)(param_1 + 0x44) + 0x50))(1);
  }
  return;
}

