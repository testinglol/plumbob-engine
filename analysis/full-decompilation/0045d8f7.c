
int __thiscall FUN_0045d8f7(int param_1,uint param_2)

{
  int iVar1;
  
  if (((int)param_2 < 0) ||
     ((uint)(*(int *)(param_1 + 0xa44) - *(int *)(param_1 + 0xa40)) <= param_2)) {
    iVar1 = 0;
  }
  else {
    iVar1 = (*(int *)(param_1 + 0xa40) + param_2 & 7) * 0x44 + param_1 + 0x820;
  }
  return iVar1;
}

