
undefined4 __thiscall FUN_00490021(int param_1,char *param_2)

{
  return CONCAT31((int3)((uint)(param_2[1] * 0xe) >> 8),
                  *(char *)(*(int *)(*(int *)(*(int *)(param_1 + 0x40 + param_2[2] * 4) + 0xc) +
                                    *param_2 * 4) + param_2[1] * 0xe) != '\0');
}

