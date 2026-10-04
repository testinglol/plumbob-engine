
uint FUN_00529ba3(int param_1)

{
  uint in_EAX;
  uint uVar1;
  
  if (((param_1 == 0) ||
      ((((((in_EAX = *(int *)(param_1 + 0x1c) - *(int *)(param_1 + 0x14), in_EAX != 0x100 &&
           (in_EAX != 0x80)) && (in_EAX != 0x40)) && ((in_EAX != 0x20 && (in_EAX != 0x10)))) &&
        ((in_EAX != 8 && ((in_EAX != 4 && (in_EAX != 2)))))) && (in_EAX != 1)))) ||
     (((((uVar1 = *(int *)(param_1 + 0x20) - *(int *)(param_1 + 0x18), uVar1 != 0x100 &&
         (uVar1 != 0x80)) && (uVar1 != 0x40)) &&
       (((uVar1 != 0x20 && (uVar1 != 0x10)) && ((uVar1 != 8 && ((uVar1 != 4 && (uVar1 != 2))))))))
      && (uVar1 != 1)))) {
    uVar1 = in_EAX & 0xffffff00;
  }
  else {
    uVar1 = CONCAT31((int3)(in_EAX >> 8),uVar1 == in_EAX);
  }
  return uVar1;
}

