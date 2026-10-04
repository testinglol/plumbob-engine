
undefined4 __thiscall FUN_004688c4(int param_1,char *param_2)

{
  return CONCAT22(param_2[1] >> 7,
                  *(undefined2 *)
                   (*(int *)(*(int *)(*(int *)(param_1 + 0x28 + param_2[2] * 4) + 0xc) +
                            *param_2 * 4) + param_2[1] * 2));
}

