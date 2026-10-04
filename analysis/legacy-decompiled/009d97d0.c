
undefined4 FUN_009d97d0(int *param_1,undefined4 param_2,undefined4 *param_3)

{
  int iVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00c50390;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((code *)*param_3 != (code *)0x0) {
    local_8 = 0;
    iVar1 = (*(code *)*param_3)(param_2,"vkBeginCommandBuffer",DAT_00dd0b80 ^ (uint)&stack0xfffffffc
                               );
    *param_1 = iVar1;
    if (iVar1 != 0) {
      local_8 = 1;
      iVar1 = (*(code *)*param_3)(param_2,"vkCmdBeginRenderPass");
      param_1[1] = iVar1;
      if (iVar1 != 0) {
        local_8 = 2;
        iVar1 = (*(code *)*param_3)(param_2,"vkCmdBindDescriptorSets");
        param_1[2] = iVar1;
        if (iVar1 != 0) {
          local_8 = 3;
          iVar1 = (*(code *)*param_3)(param_2,"vkCmdBindIndexBuffer");
          param_1[3] = iVar1;
          if (iVar1 != 0) {
            local_8 = 4;
            iVar1 = (*(code *)*param_3)(param_2,"vkCmdBindPipeline");
            param_1[4] = iVar1;
            if (iVar1 != 0) {
              local_8 = 5;
              iVar1 = (*(code *)*param_3)(param_2,"vkCmdBindVertexBuffers");
              param_1[5] = iVar1;
              if (iVar1 != 0) {
                local_8 = 6;
                iVar1 = (*(code *)*param_3)(param_2,"vkCmdBlitImage");
                param_1[6] = iVar1;
                if (iVar1 != 0) {
                  local_8 = 7;
                  iVar1 = (*(code *)*param_3)(param_2,"vkCmdClearAttachments");
                  param_1[7] = iVar1;
                  if (iVar1 != 0) {
                    local_8 = 8;
                    iVar1 = (*(code *)*param_3)(param_2,"vkCmdClearColorImage");
                    param_1[8] = iVar1;
                    if (iVar1 != 0) {
                      local_8 = 9;
                      iVar1 = (*(code *)*param_3)(param_2,"vkCmdClearDepthStencilImage");
                      param_1[9] = iVar1;
                      if (iVar1 != 0) {
                        local_8 = 10;
                        iVar1 = (*(code *)*param_3)(param_2,"vkCmdCopyBuffer");
                        param_1[10] = iVar1;
                        if (iVar1 != 0) {
                          local_8 = 0xb;
                          iVar1 = (*(code *)*param_3)(param_2,"vkCmdCopyBufferToImage");
                          param_1[0xb] = iVar1;
                          if (iVar1 != 0) {
                            local_8 = 0xc;
                            iVar1 = (*(code *)*param_3)(param_2,"vkCmdCopyImage");
                            param_1[0xc] = iVar1;
                            if (iVar1 != 0) {
                              local_8 = 0xd;
                              iVar1 = (*(code *)*param_3)(param_2,"vkCmdCopyImageToBuffer");
                              param_1[0xd] = iVar1;
                              if (iVar1 != 0) {
                                local_8 = 0xe;
                                iVar1 = (*(code *)*param_3)(param_2,"vkCmdDispatch");
                                param_1[0xe] = iVar1;
                                if (iVar1 != 0) {
                                  local_8 = 0xf;
                                  iVar1 = (*(code *)*param_3)(param_2,"vkCmdDraw");
                                  param_1[0xf] = iVar1;
                                  if (iVar1 != 0) {
                                    local_8 = 0x10;
                                    iVar1 = (*(code *)*param_3)(param_2,"vkCmdDrawIndexed");
                                    param_1[0x10] = iVar1;
                                    if (iVar1 != 0) {
                                      local_8 = 0x11;
                                      iVar1 = (*(code *)*param_3)(param_2,"vkCmdEndRenderPass");
                                      param_1[0x11] = iVar1;
                                      if (iVar1 != 0) {
                                        local_8 = 0x12;
                                        iVar1 = (*(code *)*param_3)(param_2,"vkCmdExecuteCommands");
                                        param_1[0x12] = iVar1;
                                        if (iVar1 != 0) {
                                          local_8 = 0x13;
                                          iVar1 = (*(code *)*param_3)(param_2,"vkCmdNextSubpass");
                                          param_1[0x13] = iVar1;
                                          if (iVar1 != 0) {
                                            local_8 = 0x14;
                                            iVar1 = (*(code *)*param_3)(param_2,
                                                  "vkCmdPipelineBarrier");
                                            param_1[0x14] = iVar1;
                                            if (iVar1 != 0) {
                                              local_8 = 0x15;
                                              iVar1 = (*(code *)*param_3)(param_2,
                                                  "vkCmdPushConstants");
                                              param_1[0x15] = iVar1;
                                              if (iVar1 != 0) {
                                                local_8 = 0x16;
                                                iVar1 = (*(code *)*param_3)(param_2,
                                                  "vkCmdSetScissor");
                                                param_1[0x16] = iVar1;
                                                if (iVar1 != 0) {
                                                  local_8 = 0x17;
                                                  iVar1 = (*(code *)*param_3)(param_2,
                                                  "vkCmdSetViewport");
                                                  param_1[0x17] = iVar1;
                                                  if (iVar1 != 0) {
                                                    local_8 = 0x18;
                                                    iVar1 = (*(code *)*param_3)(param_2,
                                                  "vkCreateDevice");
                                                  param_1[0x18] = iVar1;
                                                  if (iVar1 != 0) {
                                                    local_8 = 0x19;
                                                    iVar1 = (*(code *)*param_3)(param_2,
                                                  "vkDestroyDevice");
                                                  param_1[0x19] = iVar1;
                                                  if (iVar1 != 0) {
                                                    local_8 = 0x1a;
                                                    iVar1 = (*(code *)*param_3)(param_2,
                                                  "vkDestroyInstance");
                                                  param_1[0x1a] = iVar1;
                                                  if (iVar1 != 0) {
                                                    local_8 = 0x1b;
                                                    iVar1 = (*(code *)*param_3)(param_2,
                                                  "vkDestroySurfaceKHR");
                                                  param_1[0x1b] = iVar1;
                                                  if (iVar1 != 0) {
                                                    local_8 = 0x1c;
                                                    iVar1 = (*(code *)*param_3)(param_2,
                                                  "vkEndCommandBuffer");
                                                  param_1[0x1c] = iVar1;
                                                  if (iVar1 != 0) {
                                                    local_8 = 0x1d;
                                                    iVar1 = (*(code *)*param_3)(param_2,
                                                  "vkEnumerateDeviceExtensionProperties");
                                                  param_1[0x1d] = iVar1;
                                                  if (iVar1 != 0) {
                                                    local_8 = 0x1e;
                                                    iVar1 = (*(code *)*param_3)(param_2,
                                                  "vkEnumerateDeviceLayerProperties");
                                                  param_1[0x1e] = iVar1;
                                                  if (iVar1 != 0) {
                                                    local_8 = 0x1f;
                                                    iVar1 = (*(code *)*param_3)(param_2,
                                                  "vkEnumeratePhysicalDevices");
                                                  param_1[0x1f] = iVar1;
                                                  if (iVar1 != 0) {
                                                    local_8 = 0x20;
                                                    iVar1 = (*(code *)*param_3)(param_2,
                                                  "vkGetDeviceProcAddr");
                                                  param_1[0x20] = iVar1;
                                                  if (iVar1 != 0) {
                                                    local_8 = 0x21;
                                                    iVar1 = (*(code *)*param_3)(param_2,
                                                  "vkGetPhysicalDeviceFeatures");
                                                  param_1[0x21] = iVar1;
                                                  if (iVar1 != 0) {
                                                    local_8 = 0x22;
                                                    iVar1 = (*(code *)*param_3)(param_2,
                                                  "vkGetPhysicalDeviceFormatProperties");
                                                  param_1[0x22] = iVar1;
                                                  if (iVar1 != 0) {
                                                    local_8 = 0x23;
                                                    iVar1 = (*(code *)*param_3)(param_2,
                                                  "vkGetPhysicalDeviceMemoryProperties");
                                                  param_1[0x23] = iVar1;
                                                  if (iVar1 != 0) {
                                                    local_8 = 0x24;
                                                    iVar1 = (*(code *)*param_3)(param_2,
                                                  "vkGetPhysicalDeviceProperties");
                                                  param_1[0x24] = iVar1;
                                                  if (iVar1 != 0) {
                                                    local_8 = 0x25;
                                                    iVar1 = (*(code *)*param_3)(param_2,
                                                  "vkGetPhysicalDeviceQueueFamilyProperties");
                                                  param_1[0x25] = iVar1;
                                                  if (iVar1 != 0) {
                                                    local_8 = 0x26;
                                                    iVar1 = (*(code *)*param_3)(param_2,
                                                  "vkGetPhysicalDeviceSurfaceCapabilitiesKHR");
                                                  param_1[0x26] = iVar1;
                                                  if (iVar1 != 0) {
                                                    local_8 = 0x27;
                                                    iVar1 = (*(code *)*param_3)(param_2,
                                                  "vkGetPhysicalDeviceSurfaceFormatsKHR");
                                                  param_1[0x27] = iVar1;
                                                  if (iVar1 != 0) {
                                                    local_8 = 0x28;
                                                    iVar1 = (*(code *)*param_3)(param_2,
                                                  "vkGetPhysicalDeviceSurfacePresentModesKHR");
                                                  param_1[0x28] = iVar1;
                                                  if (iVar1 != 0) {
                                                    local_8 = 0x29;
                                                    iVar1 = (*(code *)*param_3)(param_2,
                                                  "vkGetPhysicalDeviceSurfaceSupportKHR");
                                                  param_1[0x29] = iVar1;
                                                  if (iVar1 != 0) {
                                                    local_8 = 0x2a;
                                                    iVar1 = (*(code *)*param_3)(param_2,
                                                  "vkResetCommandBuffer");
                                                  param_1[0x2a] = iVar1;
                                                  if (iVar1 != 0) {
                                                    local_8 = 0x2b;
                                                    iVar1 = (*(code *)*param_3)(param_2,
                                                  "vkCreateDebugUtilsMessengerEXT");
                                                  param_1[0x2b] = iVar1;
                                                  local_8 = 0x2c;
                                                  iVar1 = (*(code *)*param_3)(param_2,
                                                  "vkDestroyDebugUtilsMessengerEXT");
                                                  param_1[0x2c] = iVar1;
                                                  ExceptionList = local_10;
                                                  return 1;
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                }
                                              }
                                            }
                                          }
                                        }
                                      }
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  ExceptionList = local_10;
  return 0;
}

